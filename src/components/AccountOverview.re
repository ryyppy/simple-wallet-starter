[@react.component]
let make =
    (
      ~avatar="/static/img/default-avatar.png",
      ~name: string,
      ~address: string,
      ~balance: float,
    ) => {
  let intl = IntlNumberFormat.make(~lang=`en, {"minimumFractionDigits": 2});
  let formattedBalance = intl->IntlNumberFormat.format(balance);
  <div
    className="flex items-center bg-white rounded-lg px-6 py-8"
    style={ReactDOMStyle.make(~minWidth="34rem", ())}>
    <img className="w-32 h-32 mr-3" src=avatar />
    <div className="mt-4">
      <div className="text-16 font-bold text-blue-90">
        {React.string(name ++ "'s wallet")}
      </div>
      <Address address />
      <div className="text-36 font-bold text-blue-90 mt-4">
        {React.string(formattedBalance ++ {js| ꜩ|js})}
      </div>
    </div>
  </div>;
};
