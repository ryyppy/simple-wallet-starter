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