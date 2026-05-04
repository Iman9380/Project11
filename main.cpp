// Iman Eabeidallah
// 05/03/2026
// CIS 1202
// This program creates a function that returns a new character based on a starting letter and an offset value.
// The function checks if the starting character is a valid letter. If it is not a letter, it throws an invalidCharacterException.
// It then calculates the new character using the offset. If the result goes outside the valid range of uppercase (A–Z) or lowercase (a–z),
// it throws an invalidRangeException. Otherwise, it returns the correct character.
// The program uses try/catch blocks to test different cases and display the results or error messages.

// Include necessary headers
#include <iostream>
#include <cctype>

// Define custom exceptions
class invalidCharacterException {};
class invalidRangeException {};	

// Function prototype
char character(char start, int offset);




// Function to calculate the new character based on the starting letter and offset
char character(char start, int offset) {
	// Check if the starting character is a valid letter
	if (!std::isalpha(start)) {
		throw invalidCharacterException();
	}
	
	// Calculate the new character using the offset
	char newChar = start + offset;
	
	// Check if the new character is within the valid range of uppercase or lowercase letters
	if ((std::isupper(start) && (newChar < 'A' || newChar > 'Z')) ||
		(std::islower(start) && (newChar < 'a' || newChar > 'z'))) {
		throw invalidRangeException();
	}
	
	return newChar;
}
// MAIN FUNCTION  USE SEPARATE TRY/CATCH BLOCKS TO TEST DIFFERENT CASES
// character('a', 1) character('a', -1) character('Z', -1) character('?', 5) character ('A', 32)
int main() {
	try {
		std::cout << "character('a', 1): " << character('a', 1) << std::endl; // Should return 'b'
	} catch (const invalidCharacterException&) {
		std::cout << "Invalid character exception for character('a', 1)" << std::endl;
	} catch (const invalidRangeException&) {
		std::cout << "Invalid range exception for character('a', 1)" << std::endl;
	}
	try {
		std::cout << "character('a', -1): " << character('a', -1) << std::endl; // Should throw invalidRangeException
	} catch (const invalidCharacterException&) {
		std::cout << "Invalid character exception for character('a', -1)" << std::endl;
	} catch (const invalidRangeException&) {
		std::cout << "Invalid range exception for character('a', -1)" << std::endl;
	}
	try {
		std::cout << "character('Z', -1): " << character('Z', -1) << std::endl; // Should return 'Y'
	} catch (const invalidCharacterException&) {
		std::cout << "Invalid character exception for character('Z', -1)" << std::endl;
	} catch (const invalidRangeException&) {
		std::cout << "Invalid range exception for character('Z', -1)" << std::endl;
	}
	try {
		std::cout << "character('?', 5): " << character('?', 5) << std::endl; // Should throw invalidCharacterException
	} catch (const invalidCharacterException&) {
		std::cout << "Invalid character exception for character('?', 5)" << std::endl;
	} catch (const invalidRangeException&) {
		std::cout << "Invalid range exception for character('?', 5)" << std::endl;
	}
	try {
		std::cout << "character('A', 32): " << character('A', 32) << std::endl; // Should throw invalidRangeException
	} catch (const invalidCharacterException&) {
		std::cout << "Invalid character exception for character('A', 32)" << std::endl;
	} catch (const invalidRangeException&) {
		std::cout << "Invalid range exception for character('A', 32)" << std::endl;
	}
	return 0;
}
