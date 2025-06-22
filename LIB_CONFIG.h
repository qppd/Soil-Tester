
int found;
String split(String val, char separator, int index) {
  found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = val.length() - 1;
  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (val.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? val.substring(strIndex[0], strIndex[1]) : "";
}

