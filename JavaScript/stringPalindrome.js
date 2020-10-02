function check_Palindrome(str_entry) {
  // Change the string into lower case and remove  all non-alphanumeric characters
  var stringCheck = str_entry.toLowerCase().replace(/[^a-zA-Z0-9]+/g, "");
  var count = 0;
  // Check whether the string is empty or not
  if (stringCheck === "") {
    console.log("Nothing found!");
    return false;
  }
  // Check if the length of the string is even or odd
  if (stringCheck.length % 2 === 0) {
    count = stringCheck.length / 2;
  } else {
    // If the length of the string is 1 then it becomes a palindrome
    if (stringCheck.length === 1) {
      console.log("Entry is a palindrome.");
      return true;
    } else {
      // If the length of the string is odd ignore middle character
      count = (stringCheck.length - 1) / 2;
    }
  }
  // Loop through to check the first character to the last character and then move next
  for (var x = 0; x < count; x++) {
    // Compare characters and drop them if they do not match
    if (stringCheck[x] != stringCheck.slice(-1 - x)[0]) {
      console.log("Entry is not a palindrome.");
      return false;
    }
  }
  console.log("The entry is a palindrome.");
  return true;
}
check_Palindrome("Madam");
