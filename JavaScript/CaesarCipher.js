'''
Problem Statement : Create a function that takes a string s (text to be encrypted) and an integer k (the rotation factor). It should return an encrypted string.
'''
Solution:

function caesarCipher(s, k) {
  return s.replace(/[a-z]/gi, m => {
    const c = m < "a" ? 65 : 97;
    return String.fromCharCode((m.charCodeAt(0) - c + k) % 26 + c)
  });
}
             
             (OR)
             
function caesarCipher(s, k) {
	var cc = "";
	for (x of s){
		if (/[a-z]/.test(x)) {
			cc += String.fromCharCode(97+(x.charCodeAt()-97+k) % 26);
		} else if (/[A-Z]/.test(x)) {
			cc += String.fromCharCode(65+(x.charCodeAt()-65+k) % 26);
		} else { cc += x; }
	}
	return cc;
}

TEST_SAMPLE:
 
Test.assertEquals(caesarCipher("middle-Outz", 2), "okffng-Qwvb")
Test.assertEquals(caesarCipher("Always-Look-on-the-Bright-Side-of-Life", 5), "Fqbfdx-Qttp-ts-ymj-Gwnlmy-Xnij-tk-Qnkj")
Test.assertEquals(caesarCipher("A friend in need is a friend indeed", 20), "U zlcyhx ch hyyx cm u zlcyhx chxyyx")
Test.assertEquals(caesarCipher("A Fool and His Money Are Soon Parted.", 27), "B Gppm boe Ijt Npofz Bsf Tppo Qbsufe.")
Test.assertEquals(caesarCipher("One should not worry over things that have already happened and that cannot be changed.", 49), "Lkb pelria klq tloov lsbo qefkdp qexq exsb xiobxav exmmbkba xka qexq zxkklq yb zexkdba.")
Test.assertEquals(caesarCipher("Back to Square One is a popular saying that means a person has to start over, similar to: back to the drawing board.", 126), "Xwyg pk Omqwna Kja eo w lklqhwn owuejc pdwp iawjo w lanokj dwo pk opwnp kran, oeiehwn pk: xwyg pk pda znwsejc xkwnz.")
