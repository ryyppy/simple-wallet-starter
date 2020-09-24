type module_;
[@bs.val] external module_: module_ = "module";

// Good old hot reloader... always fun to handle that stuff!
module HotReloader = {
  type hotFn('props) =
    (. React.component('props)) => React.component('props);

  [@bs.module "react-hot-loader"]
  external hot: (. module_) => hotFn('props) = "hot";
};

// This is the core part of your App
[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let route = Route.fromAnchor(url.hash);

  let wallets = [|TezStats.Stub.bruno, TezStats.Stub.steve|];
  let (selectedWallet, setSelectedWallet) = React.useState(_ => wallets[0]);
  let page =
    switch (route) {
    | Dashboard => <Dashboard wallet=selectedWallet />
    | Transactions => <TransactionPage wallet=selectedWallet />
    | NotFound => <Page404 />
    };

  <span className="flex">
    <Sidebar currentRoute=route onSelection={w => setSelectedWallet(_ => w)} wallets />
    page
  </span>;
};

let make = (HotReloader.hot(. module_))(. make);
