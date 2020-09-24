type format =
  | Long
  | Short;

let shorten = address => {
  let length = Js.String.length(address);
  if (length < 20) {
    address;
  } else {
    let firstPart = Js.String2.substrAtMost(address, ~from=0, ~length=8);
    let lastPart = Js.String2.substr(address, ~from=length - 8);
    firstPart ++ "..." ++ lastPart;
  };
};

[@react.component]
let make = (~address: string, ~format=Long) => {
  let formattedAddress =
    switch (format) {
    | Long => address
    | Short => address->shorten
    };
  <span className="flex items-center text-14 font-bold text-grey-40">
    <Icon.Copy className="h-4 w-4 mr-2" />
    {React.string(formattedAddress)}
  </span>;
};
