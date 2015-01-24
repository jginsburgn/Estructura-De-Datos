.PHONY: clean All

All:
	@echo "----------Building project:[ GenericSearch - Debug ]----------"
	@cd "GenericSearch" && $(MAKE) -f  "GenericSearch.mk"
clean:
	@echo "----------Cleaning project:[ GenericSearch - Debug ]----------"
	@cd "GenericSearch" && $(MAKE) -f  "GenericSearch.mk" clean
