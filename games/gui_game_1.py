#!/usr/bin/env python3
import tkinter as tk
import random

class GuessingGameGUI:
    def __init__(self, root, best_score_ref):
        self.root = root
        self.root.title("Number Guessing Game")
        self.root.geometry("480x450")

        # Reference to shared best score
        self.best_score_ref = best_score_ref

        # Random number and attempts
        self.number = random.randint(1, 100000)
        self.attempts = 0

        # Title
        self.label = tk.Label(root, text="Guess a number between 1 and 100000", font=("Arial", 12))
        self.label.pack(pady=10)

        # Entry for guess
        self.entry = tk.Entry(root, font=("Arial", 12))
        self.entry.pack(pady=5)

        # Submit button
        self.button = tk.Button(root, text="Submit Guess", command=self.check_guess, font=("Arial", 12))
        self.button.pack(pady=5)

        # Feedback label
        self.feedback = tk.Label(root, text="", font=("Arial", 12))
        self.feedback.pack(pady=10)

        # Best score label
        self.best_label = tk.Label(root, text=f"Best Score: {self.best_score_ref[0] if self.best_score_ref[0] else 'None'}",
                                   font=("Arial", 12, "bold"), fg="purple")
        self.best_label.pack(pady=5)

        # Previous guesses label
        self.history_label = tk.Label(root, text="Previous guesses:", font=("Arial", 12, "bold"))
        self.history_label.pack(pady=5)

        # History display
        self.history_box = tk.Text(root, height=6, width=45, font=("Arial", 11))
        self.history_box.pack(pady=5)
        self.history_box.config(state=tk.DISABLED)

        # Buttons frame
        btn_frame = tk.Frame(root)
        btn_frame.pack(pady=10)

        # Reset button
        self.reset_button = tk.Button(btn_frame, text="Reset Game", command=self.reset_game, font=("Arial", 12))
        self.reset_button.grid(row=0, column=0, padx=5)

        # Exit button
        self.exit_button = tk.Button(btn_frame, text="Exit", command=root.quit, font=("Arial", 12), fg="white", bg="red")
        self.exit_button.grid(row=0, column=1, padx=5)

    def check_guess(self):
        guess = self.entry.get()
        if not guess.isdigit():
            self.feedback.config(text="Please enter a valid number.", fg="red")
            return

        guess = int(guess)
        self.attempts += 1

        # Update history
        self.history_box.config(state=tk.NORMAL)
        self.history_box.insert(tk.END, f"{self.attempts}: {guess}\n")
        self.history_box.see(tk.END)
        self.history_box.config(state=tk.DISABLED)

        # Game logic
        if guess == self.number:
            self.feedback.config(
                text=f"🎉 Congratulations! You guessed it in {self.attempts} attempts."
            )

            # Start animation (color flashing)
            self.animate_feedback()

            # Update best score
            if self.best_score_ref[0] is None or self.attempts < self.best_score_ref[0]:
                self.best_score_ref[0] = self.attempts
                self.best_label.config(text=f"Best Score: {self.best_score_ref[0]}")

        elif abs(guess - self.number) > 10:
            if guess < self.number:
                self.feedback.config(text="Too low!", fg="blue")
            else:
                self.feedback.config(text="Too high!", fg="blue")
        else:
            if guess < self.number:
                self.feedback.config(text="Low!", fg="orange")
            else:
                self.feedback.config(text="High!", fg="orange")

    # ---------------- ANIMATION FUNCTION ----------------
    def animate_feedback(self):
        colors = ["green", "blue", "red", "purple", "orange", "magenta"]
        current_color = getattr(self, "color_index", 0)

        self.feedback.config(fg=colors[current_color])

        # Update index for next time
        self.color_index = (current_color + 1) % len(colors)

        # Schedule next color change (every 300ms)
        self.root.after(300, self.animate_feedback)


    def reset_game(self):
        self.number = random.randint(1, 100000)
        self.attempts = 0
        self.feedback.config(text="")
        self.entry.delete(0, tk.END)

        # Clear history
        self.history_box.config(state=tk.NORMAL)
        self.history_box.delete(1.0, tk.END)
        self.history_box.config(state=tk.DISABLED)


# ---------------- START MENU ----------------
class StartMenu:
    def __init__(self, root):
        self.root = root
        self.root.title("Start Menu")
        self.root.geometry("400x250")

        # Shared best score (list so it's mutable reference)
        self.best_score_ref = [None]

        tk.Label(root, text="🎮 Number Guessing Game", font=("Arial", 16, "bold")).pack(pady=20)

        tk.Button(root, text="Start Game", font=("Arial", 14),
                  command=self.start_game).pack(pady=10)

        tk.Button(root, text="Best Score", font=("Arial", 14),
                  command=self.show_best_score).pack(pady=10)

        tk.Button(root, text="Exit", font=("Arial", 14),
                  fg="white", bg="red", command=root.quit).pack(pady=10)

    def start_game(self):
        self.root.destroy()  # Close menu
        game_root = tk.Tk()
        GuessingGameGUI(game_root, self.best_score_ref)
        game_root.mainloop()

    def show_best_score(self):
        score = self.best_score_ref[0] if self.best_score_ref[0] else "None"
        tk.messagebox.showinfo("Best Score", f"Lowest Attempts: {score}")


# ---------------- RUN APP ----------------
if __name__ == "__main__":
    root = tk.Tk()
    import tkinter.messagebox  # Needed for showinfo
    StartMenu(root)
    root.mainloop()
