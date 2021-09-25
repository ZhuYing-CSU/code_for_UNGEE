num := 100;

init:
ifndef code
	${error Argument "code" is missing}
endif

ifndef name
	${error Argument "name" is missing}
endif

	./init.sh -c ${code} -n ${name}

test:
ifndef code
	${error Argument "code" is missing}
endif
	@./test.sh -c ${code} -n ${num}