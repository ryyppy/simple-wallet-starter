// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var Route = require("./Route.js");
var React = require("react");
var Page404 = require("../pages/Page404.js");
var Sidebar = require("../pages/Sidebar.js");
var TezStats = require("./TezStats.js");
var Dashboard = require("../pages/Dashboard.js");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var TransactionPage = require("../pages/TransactionPage.js");
var ReactHotLoader = require("react-hot-loader");
var ReasonReactRouter = require("reason-react/src/ReasonReactRouter.js");

var HotReloader = {};

function App(Props) {
  var url = ReasonReactRouter.useUrl(undefined, undefined);
  var route = Route.fromAnchor(url.hash);
  var wallets = [
    TezStats.Stub.bruno,
    TezStats.Stub.steve
  ];
  var match = React.useState(function () {
        return Caml_array.get(wallets, 0);
      });
  var setSelectedWallet = match[1];
  var selectedWallet = match[0];
  var page;
  switch (route) {
    case /* Dashboard */0 :
        page = React.createElement(Dashboard.make, {
              wallet: selectedWallet
            });
        break;
    case /* Transactions */1 :
        page = React.createElement(TransactionPage.make, {
              wallet: selectedWallet
            });
        break;
    case /* NotFound */2 :
        page = React.createElement(Page404.make, {});
        break;
    
  }
  return React.createElement("span", {
              className: "flex"
            }, React.createElement(Sidebar.make, {
                  currentRoute: route,
                  wallets: wallets,
                  onSelection: (function (w) {
                      return Curry._1(setSelectedWallet, (function (param) {
                                    return w;
                                  }));
                    })
                }), page);
}

var make = ReactHotLoader.hot(module)(App);

exports.HotReloader = HotReloader;
exports.make = make;
/* make Not a pure module */
