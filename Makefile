.PHONY: build-client build-server build

build-client:
	gcc -o ./build/client ./src_client/main.c

build-server:
	gcc -o ./build/server ./src_server/main.c

build: build-client build-server

run-client: build-client
	./build/client

run-server: build-server
	./build/server
