void clearConsole() {
	#ifdef _WIN32
		system("cls");  // Windows
	#else
		system("clear"); // (Linux/MacOS)
	#endif
}

void log() {
	clearConsole();
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "rotationAngle\t" << rotateAngle << "\n";
	std::cout << "actualDaytime\t" << actualDaytime << "\n";
	std::cout << "actualCarColor\t" << actual_car_color << "\n";
}