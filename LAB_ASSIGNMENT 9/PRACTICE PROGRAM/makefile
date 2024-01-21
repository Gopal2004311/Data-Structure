%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@
	
$(BIN):$(OBJ)
	$(CC) $(CFLAGS) $(BIN).c $^ -o $@

vis: $(BIN)
	./$(BIN) | dot - Tpdf > vis.pdf

clean:
	$(RM) -r $(BIN) $(OBJ) *.dSYM vis.pdf