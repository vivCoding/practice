CC = g++

OUTDIR = bin

%: %.cpp
	@mkdir -p $(OUTDIR)
	@$(CC) -o $(OUTDIR)/$@ $<

clean:
	@rm -r $(OUTDIR)
	@echo "Cleaned up all binaries."