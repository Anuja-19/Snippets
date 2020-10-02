

import io.vertx.core.AbstractVerticle;

public class HelloVerticle extends AbstractVerticle {

    @Override
    public void start() throws Exception {
        vertx.createHttpServer().requestHandler(request -> {
            request.response().end("Hello Ethos from VertX!");
        }).listen(8080);
    }
}
