
open Models;

[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

type target = {
  name: string,
  ip: string,
  port: string
};

type state = 
  | LoadingSummary
  | ErrorLoadingSummary
  | LoadedSummary(monData);


let getUrl = (ip, port) => "http://localhost:9000/data?ip=" ++ ip ++ "&port=" ++ port ++ "&type=dynamic.json";

let renderLoading = () => 
    <div>{ReasonReact.string("Loading...")}</div>;

let renderError = () => 
    <div>{ReasonReact.string("Error!")}</div>;

[@react.component]
let make = (~target: target) => {
  let (state, setState) = React.useState(()=> LoadingSummary);
  React.useEffect0(() => {
    Js.Promise.(
      fetch(getUrl(target.ip, target.port))
      |> then_(response => response##json())
      |> then_(jsonResponse => {
            setState(_previousState => LoadedSummary(jsonResponse));
            Js.Promise.resolve();
      })
      |> catch(_err => {
           setState(_previousState => ErrorLoadingSummary);
           Js.Promise.resolve();
         })
      |> ignore
    );
    None;
  });

  <Container title={target.name}>
    {switch(state){
      | ErrorLoadingSummary => renderError()
      | LoadingSummary => renderLoading()
      | LoadedSummary(monData) => <Summary data={monData} />
    }}
  </Container>;
}


