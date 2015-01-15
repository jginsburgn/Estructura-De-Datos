.PHONY: clean All

All:
	@echo "----------Building project:[ Hanoi - Debug ]----------"
	@cd "Hanoi" && $(MAKE) -f  "Hanoi.mk"
clean:
	@echo "----------Cleaning project:[ Hanoi - Debug ]----------"
	@cd "Hanoi" && $(MAKE) -f  "Hanoi.mk" clean
