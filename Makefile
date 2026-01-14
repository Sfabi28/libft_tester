SHELL := /bin/bash
.PHONY: all run

all: run

run:
	@chmod +x .launch.sh || true
	@./.launch.sh

%:
	@chmod +x .launch.sh || true
	@./.launch.sh $@