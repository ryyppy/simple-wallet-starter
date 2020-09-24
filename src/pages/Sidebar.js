// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var Link = require("../components/Link.js");
var React = require("react");

function Sidebar(Props) {
  return React.createElement("div", {
              className: "w-1/4 bg-blue-dark text-white h-screen"
            }, React.createElement("div", {
                  className: "ml-4"
                }, React.createElement("div", undefined, React.createElement(Link.make, {
                          href: "foo",
                          children: "Dashboard"
                        })), React.createElement("div", undefined, React.createElement(Link.make, {
                          href: "bar",
                          children: "Transactions"
                        }))));
}

var make = Sidebar;

exports.make = make;
/* Link Not a pure module */