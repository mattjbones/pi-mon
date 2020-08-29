[@react.component]
let make = (~children, ~title) => <div className="container">
  <div className="containerTitle">{ReasonReact.string(title)}</div>
  <div className="containerContent">{children}</div>
</div>