type t =
  | Dashboard
  | Transactions
  | NotFound;

let fromAnchor = (url: string) => {
  switch (url) {
  | ""
  | "dashboard" => Dashboard
  | "transactions" => Transactions
  | _ => NotFound
  };
};

let toHref = (t: t) =>
  switch (t) {
  | Dashboard => "#dashboard"
  | Transactions => "#transactions"
  | NotFound => "#page404"
  };

let toString = (t: t) =>
  switch (t) {
  | Dashboard => "Dashboard"
  | Transactions => "Transactions"
  | NotFound => ""
  };
