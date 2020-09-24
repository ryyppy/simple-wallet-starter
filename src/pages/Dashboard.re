module Clicker = {
  type data =
    | Init
    | Loading
    | Success(string)
    | Failed(string);

  [@react.component]
  let make = () => {
    let (count, setCount) = React.useState(_ => 0);

    let (data, setData) = React.useState(_ => Init);

    React.useEffect1(
      () => {
        setData(_ => Loading);
        let watchId =
          Js.Global.setTimeout(
            () => {
              setData(_ =>
                Success("Found 123 (" ++ Belt.Int.toString(count) ++ ")")
              )
            },
            Js.Math.abs_int(1000 * count),
          );

        let cleanup = () => {
          Js.Global.clearTimeout(watchId);
        };

        Some(cleanup);
      },
      [|count|],
    );

    let increase = evt => {
      ReactEvent.Mouse.preventDefault(evt);
      setCount(prev => prev + 1);
    };
    let decrease = evt => {
      ReactEvent.Mouse.preventDefault(evt);
      setCount(prev => prev - 1);
    };

    let dataElement =
      switch (data) {
      | Init
      | Loading => React.string("Loading...")
      | Success(data) => React.string(data)
      | Failed(msg) => React.string("Failed with " ++ msg)
      };

    let buttonClass = "text-16 w-4 h-4 rounded bg-grey-10";
    <div className="flex items-center justify-center bg-blue w-1/3 h-20">
      <div> <h2> dataElement </h2> </div>
      <div>
        <button onClick=decrease className=buttonClass>
          {React.string("-")}
        </button>
        <span className="w-8 font-bold text-36"> {React.int(count)} </span>
        <button onClick=increase className=buttonClass>
          {React.string("+")}
        </button>
        <button onClick={_evt => setCount(_ => 0)}>
          {React.string("Reset")}
        </button>
      </div>
    </div>;
  };
};

type state =
  | Init
  | Loading
  | Success(TezStats.Account.t)
  | Failed(string);

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
        TezStats.Account.query(
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
    | Success(account) =>
      <AccountOverview
        avatar=?{wallet.avatar}
        name={wallet.name}
        address={account.address}
        balance={account.total_balance}
      />
    | Failed(error) => <div> {React.string(error)} </div>
    };
  <MainLayout>
    <div className="w-full" style={ReactDOMStyle.make(~maxWidth="34rem", ())}>
      content
    </div>
  </MainLayout>;
};
