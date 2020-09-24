type request;
type response;

[@bs.new] external makeXMLHttpRequest: unit => request = "XMLHttpRequest";
[@bs.send]
external addEventListener: (request, string, unit => unit) => unit =
  "addEventListener";
[@bs.get] external response: request => response = "response";
[@bs.send] external open_: (request, string, string) => unit = "open";
[@bs.send] external send: request => unit = "send";
[@bs.send] external abort: request => unit = "abort";

[@bs.get] external status: request => int = "status";

let endpoint = "https://api.tzstats.com";

module Stub = {
  let mockup_address2 = "tz1bDXD6nNSrebqmAnnKKwnX1QdePSMCj4MX";
  let mockup_address = "tz1fvLppfweTwyfrW7WuqKVicVJkWB7bJV6y";
  let bruno: Wallet.t = {
    avatar: None,
    name: "Bruno",
    address: mockup_address,
  };
  let steve: Wallet.t = {
    avatar: None,
    name: "Steve",
    address: mockup_address2,
  };
};

module Transaction = {
  type t = {
    row_id: float,
    receiver: option(string),
    sender: string,
    fee: float,
    volume: float,
    time: string,
  };

  [@bs.scope "JSON"] [@bs.val]
  external parseResponse: response => array(t) = "parse";

  let queryByAddress =
      (
        ~address: string,
        ~onDone: array(t) => unit,
        ~onError: int => unit,
        (),
      ) => {
    let request = makeXMLHttpRequest();
    request->open_(
      "GET",
      "https://api.tzstats.com/explorer/account/" ++ address ++ "/operations",
    );
    request->addEventListener("load", () => {
      let response = request->response;
      let parsedResponse = parseResponse(response);
      onDone(parsedResponse);
    });
    request->addEventListener("error", () => {
      let status = request->status;
      onError(status);
    });
    request->send;
    () => request->abort;
  };
};

module Account = {
  type t = {
    address: string,
    total_balance: float,
  };

  [@bs.scope "JSON"] [@bs.val] external parseResponse: response => t = "parse";

  let query =
      (~address: string, ~onDone: t => unit, ~onError: int => unit, ()) => {
    let request = makeXMLHttpRequest();
    request->open_(
      "GET",
      "https://api.tzstats.com/explorer/account/" ++ address,
    );
    request->addEventListener("load", () => {
      let response = request->response;
      let parsedResponse = parseResponse(response);
      onDone(parsedResponse);
    });
    request->addEventListener("error", () => {
      let status = request->status;
      onError(status);
    });
    request->send;
    () => request->abort;
  };
};
