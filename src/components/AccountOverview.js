// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var Icon = require("../common/Icon.js");
var React = require("react");

function AccountOverview(Props) {
  var avatar = Props.avatar;
  var name = Props.name;
  var address = Props.address;
  var balance = Props.balance;
  var intl = new (Intl.NumberFormat)("en-US", {
        minimumFractionDigits: 2
      });
  var formatedBalance = intl.format(balance);
  return React.createElement("div", {
              className: "flex items-center justify-center bg-white rounded-lg px-6 py-8"
            }, React.createElement("div", {
                  className: "mr-6"
                }, React.createElement("img", {
                      className: "w-32",
                      src: avatar
                    })), React.createElement("div", {
                  className: "mt-4"
                }, React.createElement("div", {
                      className: "text-16 font-bold text-blue-90"
                    }, name + "'s wallet"), React.createElement("span", {
                      className: "flex items-center text-14 font-bold text-grey-40"
                    }, React.createElement(Icon.Copy.make, {
                          className: "h-4 w-4 mr-2"
                        }), address), React.createElement("div", {
                      className: "text-36 font-bold text-blue-90 mt-4"
                    }, formatedBalance + " ꜩ")));
}

var make = AccountOverview;

exports.make = make;
/* Icon Not a pure module */