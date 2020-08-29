import {
  Application,
  Router,
  helpers,
} from "https://deno.land/x/oak@v6.0.2/mod.ts";
import type { Context } from "https://deno.land/x/oak@v6.0.2/mod.ts";
import { contentType } from "https://deno.land/x/media_types@v2.4.5/mod.ts";

const port = 9000;

const router: Router = new Router();
router
  .get("/", (context: Context) => {
    context.response.body = "Hello World!";
  })
  .get("/data", async (context: Context) => {
    const { response } = context;
    const query = helpers.getQuery(context);
    const { ip, port, type } = query;
    if (!ip && !port && !type) {
      response.status = 500;
      response.body = { error: "missing args" };
    } else {
      const res = await fetch(`http://${ip}:${port}/${type}`);
      const body = new Uint8Array(await res.arrayBuffer());
      response.headers.set("Access-Control-Allow-Origin", "*");
      response.headers.set("Content-Type", "application/json");
      response.status = 200;
      response.body = body;
    }
  });

const app = new Application();
app.use(router.routes());
app.use(router.allowedMethods());

console.log(`Starting server on ${port}`);
await app.listen({ port });
