all:
	clang -emit-llvm -c main.c
	clang -emit-llvm -c foo.c
	llvm-link-3.4 main.bc foo.bc > out.bc
	lli-3.4 out.bc
	llvm-dis-3.4 out.bc

clean:
	rm -f *.bc *.ll