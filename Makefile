OBJS		= Main.o ItemType.o BinaryTree.o
COMPILE		= g++ -g -c -std=gnu++0x -o $@

# the main target
main: $(OBJS)
	g++ -o $@ $(OBJS)
	
# dependencies
Main.o: Main.cpp
	$(COMPILE) Main.cpp
	
ItemType.o: ItemType.h ItemType.cpp
	$(COMPILE) ItemType.cpp
	
BinaryTree.o: BinaryTree.h  BinaryTree.cpp
	$(COMPILE) BinaryTree.cpp
	
clean:
	$(RM) $(OBJS)
	
cleanall: clean
	$(RM) main
