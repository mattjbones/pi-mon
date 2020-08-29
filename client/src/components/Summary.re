open Models;

let secsInMin = 60.0;
let minsInHour = 60.0;
let hoursInDay = 24.0;
let daysInYear = 365.0;

let secondsInHour = secsInMin *. minsInHour;
let seconsInDay = secondsInHour *. hoursInDay;
let secondsInYear = seconsInDay *. daysInYear;


type timeParts = {
  years: int,
  days: int,
  hours: int,
  minutes: int,
  secs: int  
}

let getTimeParts = (totalSecsString) => {
  let totalSecs = float_of_string(totalSecsString);
  let years =  totalSecs /. secondsInYear;
  let days = mod_float(years, 1.0) *. daysInYear;
  let hours = mod_float(days, 1.0) *. hoursInDay;
  let minutes = mod_float(hours, 1.0) *. minsInHour;
  let secs = mod_float(minutes, 1.0) *. secsInMin;
  { years:int_of_float(years), days:int_of_float(days), hours:int_of_float(hours), minutes:int_of_float(minutes), secs: int_of_float(secs) }
};

let getTimeString = ({ years, days, hours, minutes, secs}) => {
  let yearString = (years > 0 ) ? string_of_int(years) ++ " years, " : "";
  let dayString = (days > 0) ? string_of_int(days) ++ " days, " : "";
  let hourString = (hours > 0) ? string_of_int(hours) ++ " hours, " : "";
  let minuteString = (minutes > 0) ? string_of_int(minutes) ++ " minutes, " : "";
  let secString = (secs > 0) ? string_of_int(secs) ++ " seconds" : "";
  yearString ++ dayString ++ hourString ++ minuteString ++ secString;
};

[@react.component]
let make = (~data) => 
  <>
    <div>{ReasonReact.string("Uptime: " ++ getTimeString(getTimeParts(data.uptime)) )}</div>
    <div>{ReasonReact.string("Load: " ++ data.load1 )}</div>
    <div>{ReasonReact.string("Temp: " ++ data.soc_temp )}</div>
  </>