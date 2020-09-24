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
  <span className="flex">
    <Sidebar/>
    <Dashboard/>
  </span>;
}

let make = (HotReloader.hot(. module_))(. make);