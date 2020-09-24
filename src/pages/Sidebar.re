[@react.component]
let make = () => {
  <div className="w-1/4 bg-blue-dark text-white h-screen">
    <div className="ml-4">
      <div> <Link href="foo"> {React.string("Dashboard")} </Link> </div>
      <div> <Link href="bar"> {React.string("Transactions")} </Link> </div>
    </div>
  </div>;
};
