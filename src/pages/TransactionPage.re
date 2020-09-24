type state =
  | Init
  | Loading
  | Success(array(TezStats.Transaction.t))
  | Failed(string);

module TransactionIcon = {
  [@react.component]
  let make = (~isPaid: bool) => {
    let colorClass =
      isPaid ? "bg-green-light text-green" : "bg-red-10-tr text-red";
    let icon = isPaid ? <Icon.ArrowUp /> : <Icon.ArrowDown />;
    <div className={"px-1 py-1 rounded-md " ++ colorClass}> icon </div>;
  };
};

let intl = IntlNumberFormat.make(~lang=`en, {"minimumFractionDigits": 2});

let styledVolume = (~isPaid: bool, volume: float) => {
  let formattedVolume = intl->IntlNumberFormat.format(volume);
  let className = isPaid ? "text-green" : "text-red";
  let minus = isPaid ? React.null : React.string("- ");
  <div className> minus {React.string(formattedVolume)} </div>;
};

module TransactionHistory = {
  [@react.component]
  let make = (~address: string, ~transactions: array(TezStats.Transaction.t)) => {
    let content =
      transactions->Belt.Array.map(t => {
        let isPaid =
          switch (t.receiver) {
          | Some(receiver) => receiver === address
          | None => false
          };
        let className = "px-3 py-3 border-t border-grey-10";
        <tr key={Belt.Float.toString(t.row_id)}>
          <td className> <TransactionIcon isPaid /> </td>
          <td className>
            <Address address={t.sender} format=Address.Short />
          </td>
          <td className>
            {t.receiver
             ->Belt.Option.mapWithDefault(React.null, address =>
                 <Address address format=Address.Short />
               )}
          </td>
          <td className={className ++ " text-right"}> {styledVolume(~isPaid, t.volume)} </td>
        </tr>;
      });
    let className = "text-left uppercase px-3 pb-2";
    <div className="h-full rounded-md text-blue-90 px-6 py-6 bg-white">
      <div className="text-16 font-bold mb-3">
        {React.string("Transaction History")}
      </div>
      <table>
        <thead className="">
          <tr className="text-10">
            <th className> <Icon.UpDownArrow /> </th>
            <th className> {React.string("SENDER")} </th>
            <th className> {React.string("RECEIVER")} </th>
            <th className={className ++ " text-right"}> {React.string("VOLUME (" ++ {js|ꜩ|js} ++ ")")} </th>
          </tr>
        </thead>
        <tbody> {React.array(content)} </tbody>
      </table>
    </div>;
  };
};

[@react.component]
let make = (~wallet: Wallet.t) => {
  let (state, setState) = React.useState(_ => Init);
  React.useEffect1(
    () => {
      setState(_ => Loading);
      let onDone = data => setState(_ => Success(data));
      let onError = code =>
        setState(_ => Failed("Error code:" ++ Belt.Int.toString(code)));
      let cancel =
        TezStats.Transaction.queryByAddress(
          ~address=wallet.address,
          ~onDone,
          ~onError,
          (),
        );
      Some(cancel);
    },
    [|wallet.address|],
  );
  let content =
    switch (state) {
    | Init
    | Loading => <div> {React.string("...")} </div>
    | Success(transactions) =>
      <TransactionHistory address={wallet.address} transactions />
    | Failed(_) => <div />
    };
  <MainLayout> content </MainLayout>;
};
