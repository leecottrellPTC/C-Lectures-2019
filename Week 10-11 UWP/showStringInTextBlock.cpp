
void convertString(string oldString, wstring &newString) {
	for (int x = 0; x < oldString.length(); x++) {
		newString[x] = oldString[x];
	}
}
This is your event()
{
	
	
	const string normal = "Damn it";
	std::wstring convString(normal.length(), L'A');
	convertString(normal, convString);
	String^ managed = ref new String(convString.c_str());
	this->outBox->Text = managed;
	
}
