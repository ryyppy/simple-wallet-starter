// Generated by ReScript, PLEASE EDIT WITH CARE
'use strict';

var Icon = require("../common/Icon.js");
var React = require("react");

function shorten(address) {
  var length = address.length;
  if (length < 20) {
    return address;
  }
  var firstPart = address.substr(0, 8);
  var lastPart = address.substr(length - 8 | 0);
  return firstPart + ("..." + lastPart);
}

function Address(Props) {
  var address = Props.address;
  var formatOpt = Props.format;
  var format = formatOpt !== undefined ? formatOpt : /* Long */0;
  var formattedAddress = format ? shorten(address) : address;
  return React.createElement("span", {
              className: "flex items-center text-14 font-bold text-grey-40"
            }, React.createElement(Icon.Copy.make, {
                  className: "h-4 w-4 mr-2"
                }), formattedAddress);
}

var make = Address;

exports.shorten = shorten;
exports.make = make;
/* Icon Not a pure module */
