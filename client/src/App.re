[@react.component]
let make = () =>
  <>
    <Welcome name="Matt" />
    <DataSummary target={{name: "Pihole", ip: "192.168.0.100", port: "8888"}}/>
    <DataSummary target={{name: "Homebridge", ip: "192.168.0.206", port: "8888"}}/>
    <DataSummary target={{name: "Pi3", ip: "192.168.0.219", port: "8888"}}/>
  </>;