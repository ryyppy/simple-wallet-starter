module Clipboard = {
  [@react.component]
  let make = (~className: string="") => {
    <svg
      width="24"
      height="24"
      viewBox="0 0 24 24"
      fill="none"
      strokeWidth="2"
      strokeLinecap="round"
      strokeLinejoin="round"
      className={"stroke-current " ++ className}>
      <path
        d="M16 4h2a2 2 0 012 2v14a2 2 0 01-2 2H6a2 2 0 01-2-2V6a2 2 0 012-2h2"
      />
      <rect x="8" y="2" width="8" height="4" rx="1" ry="1" />
    </svg>;
  };
};

module Copy = {
  [@react.component]
  let make = (~className="") => {
    <svg
      width="24"
      height="24"
      viewBox="0 0 24 24"
      fill="none"
      strokeWidth="2"
      strokeLinecap="round"
      strokeLinejoin="round"
      className={"stroke-current " ++ className}>
      <rect x="9" y="9" width="13" height="13" rx="2" ry="2" />
      <path d="M5 15H4a2 2 0 01-2-2V4a2 2 0 012-2h9a2 2 0 012 2v1" />
    </svg>;
  };
};

module ArrowUp = {
  [@react.component]
  let make = (~className="") => {
    <svg
      width="24"
      height="24"
      viewBox="0 0 24 24"
      fill="none"
      strokeWidth="2"
      strokeLinecap="round"
      strokeLinejoin="round"
      className={"stroke-current " ++ className}>
      <path d="M12 19V5M5 12l7-7 7 7" />
    </svg>;
  };
};

module VerticalDots = {
  [@react.component]
  let make = (~className="") => {
    <svg
      width="24"
      height="24"
      viewBox="0 0 24 24"
      fill="none"
      stroke="currentColor"
      strokeWidth="2"
      strokeLinecap="round"
      strokeLinejoin="round"
      className={"stroke-current " ++ className}>
      <circle cx="12" cy="12" r="1" />
      <circle cx="12" cy="5" r="1" />
      <circle cx="12" cy="19" r="1" />
    </svg>;
  };
};