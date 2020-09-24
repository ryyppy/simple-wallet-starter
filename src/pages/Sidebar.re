[@react.component]
let make = () => {
  <div className="w-1/4 bg-blue-dark text-white h-screen">
    <div className="ml-4">
      <div> <Link route=Dashboard> {React.string("Dashboard")} </Link> </div>
      <div> <Link route=Transactions> {React.string("Transactions")} </Link> </div>
    </div>
  </div>;
};
