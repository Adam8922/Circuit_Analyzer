# Circuit Resistance Calculator

Hey there! 👋 I'm Adam Ahmed, and this is my circuit resistance calculator project. I've implemented solutions in both C++ and Python that can compute total resistance from string descriptions of electrical circuits.

## 🧠 What I Built

I created a program that understands circuit descriptions like:
- `S 10 20 30 e` (Series connection)
- `P 5 S 2 3 e e` (Parallel with nested Series)

**Key features:**
- ✅ Handles both simple and complex nested circuits
- ✅ Works with any number of resistors (up to 20)
- ✅ Proper error checking for invalid inputs
- ✅ Clean output showing total resistance

## 💡 How It Works

- I used recursive parsing to handle nested connections. Here's my approach:
  1. Parse the input string character by character
  2. Detect connection types (S/P) and resistor values
  3. Calculate recursively:
     - Series: R₁ + R₂ + ... + Rₙ
     - Parallel: 1/(1/R₁ + 1/R₂ + ... + 1/Rₙ)
  4. Handle errors for invalid inputs
    
## 🧪 Test Cases I Considered

Here are some examples I tested:

- S 1 2 3 e --->	6.0
- P 2 2 e --->	1.0
- S 1 P 2 2 e e --->	2.0
- P 1 X 2 e e --->	"Wrong Description"

## 🎓 What I Learned

Through this project, I:
- Mastered recursive algorithms for parsing nested structures
- Improved my error handling skills
- Learned to implement the same logic in both C++ and Python
- Gained deeper understanding of circuit analysis

## 🤝 Contributing

While this was a school project, I'm open to suggestions! If you spot any bugs or have ideas for improvement, feel free to open an issue.

## 📧 Contact Me

Have questions about my implementation? Reach out!
- Email: [adamelarabyofficial@gmail.com](mailto:adamelarabyofficial@gmail.com)

---

Thanks for checking out my project! Hope you find it interesting 😊
