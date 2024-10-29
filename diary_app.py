import tkinter as tk
from datetime import datetime

# Function to save the response to a text file
def save_response():
    response = entry.get()  # Get text from entry field
    if response:
        # Save the response with the current date and time
        with open("diary_entries.txt", "a") as file:
            file.write(f"{datetime.now().strftime('%Y-%m-%d %H:%M:%S')}: {response}\n")
        # Clear the entry field after saving
        entry.delete(0, tk.END)
        label.config(text="Response saved! How are you feeling today?")  # Update label

# Create the main window
root = tk.Tk()
root.title("Diary App")
root.geometry("300x200")

# Label to ask how you feel
label = tk.Label(root, text="How are you feeling today?", font=("Arial", 12))
label.pack(pady=10)

# Entry field to type the response
entry = tk.Entry(root, width=30)
entry.pack(pady=5)

# Button to submit the response
save_button = tk.Button(root, text="Save", command=save_response)
save_button.pack(pady=20)

# Start the main loop
root.mainloop()
