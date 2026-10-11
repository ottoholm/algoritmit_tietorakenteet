#include <iostream>
#include <cstdio>
#include "stack.h"

int main(int argc, char** argv) {

	// Check amount of parameters (argc)
	if (argc < 2) {
		std::cout << "Not enough arguments! You called: " << argv[0] << std::endl;
		return EXIT_FAILURE;
	}
	else {
		std::cout << "OK, You called: " << argv[0] << " " << argv[1] << std::endl;
		FILE* fp = NULL;
		errno_t error = fopen_s(&fp,argv[1], "r");

		if (fp == NULL) {
			std::cout << "Error opening file: " << argv[1] << std::endl;
			return EXIT_FAILURE;
		}

		// Now start reading the file one char at a time:
		Stack<std::string> tagStack;

		char c;
		bool insideTag = false;	// Checkker if inside of a start <tag>
		bool nameDone = false;	// So ignores any property definitions inside the tag <>
		std::string tag;		// Store the start of tags
		bool ok = true;			// Was the file ok

		while ((c = std::fgetc(fp)) != EOF) {

			// Start of the tag
			if (c == '<') {
				tag.clear();
				nameDone = false;
				insideTag = true;
			}		
			// End of the tag
			else if (c == '>') {
				insideTag = false;

				if (tag[0] == '/') { // If it was a end tag, lets compare to the last one
					std::string name = tag.substr(1); 

					// Stack is empty 
					if (tagStack.IsEmpty()) {
						std::cout << "Error: No start tag for this end tag: " << name << std::endl;
						ok = false;
						break;
					}

					// Previous tag is not the same as the end tag 
					std::string top = tagStack.Pop();
					if (top != name) {
						std::cout << "Error: Previous tag: " << top << " is not the same as the end tag: " << name << std::endl;
						ok = false;
						break;
					}
				}
				// start of a tag so push it to stack, if it is not a void element
				else if (tag != "area" && tag != "base" &&
						tag != "br" && tag != "col" &&
						tag != "embed" && tag != "hr" &&
						tag != "img" && tag != "input" &&
						tag != "link" && tag != "meta" &&
						tag != "param" && tag != "source" &&
						tag != "track" && tag != "wbr") {
					tagStack.Push(tag);
				}
			}
			// Inside the tag so store everyting to the tag string
			else if (insideTag) {
				if (tag.empty() == false && c == ' ') {  // ingnores everything after the tag
					nameDone = true;
				}
				else if (nameDone == false && c != ' ') { //ingnores whitespaces before tag 
					tag += static_cast<char>(c);
				}
			}
		}
		// If stack is not empty after checking every tag -> error
		if (ok && tagStack.IsEmpty() == false) {
			std::cout << "Error: There are still unchecked tags: " << std::endl;
			while (tagStack.IsEmpty() == false) {
				std::cout << "  <" << tagStack.Pop() << ">" << std::endl;
			}
			ok = false;
		}

		if (ok) {
			std::cout << "HTML file was OK" << std::endl;
		}

		std::fclose(fp); // Remember to close the file!
		return EXIT_SUCCESS;
	}
	 

	/*
	// Int stack
	Stack<int> s;
	for (int i = 0; i < 10; i++) {			// Push data 0-9
		sInt.Push(i);
		std::cout << s.Top() << std::endl;
	}
	std::cout << "^---end push---begin pop------------->" << std::endl;
	for (int i = 0; i < 10; i++) {			// Pop data  9-0
		int value = s.Pop();
		std::cout << value << std::endl;
	}
	*/

	return EXIT_SUCCESS;
}