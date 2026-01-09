import random

# Generate a fake server log with 1 Million lines
log_levels = ["INFO", "WARNING", "ERROR", "CRITICAL"]
messages = ["Database connection failed", "User logged in", "Page load slow", "Payment processed"]

print("Generating 1 Million Log Lines... (This might take 5 seconds)")

with open("server_logs.txt", "w") as f:
    for i in range(1000000): # 1 Million rows
        level = random.choice(log_levels)
        msg = random.choice(messages)
        # Format: TIMESTAMP | LEVEL | MESSAGE
        f.write(f"2024-01-08 10:00:{i%60} | {level} | {msg}\n")

print("✅ Done! 'server_logs.txt' created.")