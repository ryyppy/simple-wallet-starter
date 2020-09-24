[@react.component]
let make =
    (
      ~currentRoute: Route.t,
      ~wallets: array(Wallet.t),
      ~onSelection: Wallet.t => unit,
    ) => {
  let walletLinks =
    wallets->Belt.Array.map(w => {
      let onClick = event => {
        onSelection(w);
        event->ReactEvent.Mouse.preventDefault;
      };
      <li key=w.address className="cursor-pointer" onClick> {React.string(w.name)} </li>;
    });
  let navLinks =
    [|Route.Dashboard, Transactions|]
    ->Belt.Array.map(route => {
        let activeclass = route === currentRoute ? "bg-blue -mx-4 pl-4" : "";
        let text = route->Route.toString;
        <li key=text className={activeclass ++ " py-2"}>
          <Link route> {text->React.string} </Link>
        </li>;
      });
  <div className="w-1/4 bg-blue-dark text-white h-screen">
    <div className="ml-4"> <ul> {React.array(walletLinks)} </ul> </div>
    <div className="ml-4 mt-10"> <ul> {React.array(navLinks)} </ul> </div>
  </div>;
};
