.PHONY: clean All

All:
	@echo "----------Building project:[ RecursiveMatrixComponentAdder - Debug ]----------"
	@cd "RecursiveMatrixComponentAdder" && $(MAKE) -f  "RecursiveMatrixComponentAdder.mk"
clean:
	@echo "----------Cleaning project:[ RecursiveMatrixComponentAdder - Debug ]----------"
	@cd "RecursiveMatrixComponentAdder" && $(MAKE) -f  "RecursiveMatrixComponentAdder.mk" clean
