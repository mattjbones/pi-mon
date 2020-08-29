# PiMon

A small web app that acts as a front end for the excellent https://github.com/XavierBerger/RPi-Monitor.

With **PiMon** configure multiple IP addresses of instances of RPi-Monitor to get a summary dashbaord each pi.

## Getting started

**PiMon** is a monorepo with a `client` / `server` setup.

### Client

A [ReasonML](http://reasonml.github.io) client which displays stats on each configured device. Configured using `yarn`.

Start with `yarn start` and `yarn server`.

### Server

A small [Deno](http://deno.land/) / [Oak](https://github.com/oakserver/oak) server which acts as a go between for the client and the pi's. Configured using `make`

Start with `make`
