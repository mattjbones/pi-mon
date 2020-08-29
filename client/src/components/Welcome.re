[@react.component]
let make = (~name) => 
  <Container title="Welcome">
    <div>{ReasonReact.string("Hello " ++ name)}</div>
  </Container>;
