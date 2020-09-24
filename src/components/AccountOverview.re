[@react.component]
let make = (~avatar: string, ~name: string, ~address: string, ~balance: float) => {
  let intl = IntlNumberFormat.make(~lang=`en, {"minimumFractionDigits": 2});
  let formatedBalance = intl->IntlNumberFormat.format(balance);
  <div
    className="flex items-center justify-center bg-white rounded-lg px-6 py-8">
    <div className="mr-6"> <img className="w-32" src=avatar /> </div>
    <div className="mt-4">
      <div className="text-16 font-bold text-blue-90">
        {React.string(name ++ "'s wallet")}
      </div>
      <span className="flex items-center text-14 font-bold text-grey-40">
        <Icon.Copy className="h-4 w-4 mr-2" />
        {React.string(address)}
      </span>
      <div className="text-36 font-bold text-blue-90 mt-4">
        {React.string(formatedBalance ++ {js| ꜩ|js})}
      </div>
    </div>
  </div>;
};
