def display_stack(stack):
    print("\nStack saat ini:")
    for item in reversed(stack):
        print(f"| {item} |")
    print("-------")

def main():
    stack = []
    MAX_STACK = 10
    
    while True:
        print("\nPilih operasi:")
        print("1. Push")
        print("2. Pop")
        print("3. Quit")
        choice = input("Masukkan pilihan (1/2/3): ")
        
        if choice == "1":
            if len(stack) < MAX_STACK:
                char = input("Masukkan karakter: ")
                if len(char) == 1:
                    stack.append(char)
                else:
                    print("Harap masukkan hanya satu karakter!")
            else:
                print("Stack penuh! Tidak dapat menambahkan elemen.")
        elif choice == "2":
            if stack:
                popped = stack.pop()
                print(f"Elemen '{popped}' dihapus dari stack.")
            else:
                print("Stack kosong! Tidak ada elemen untuk dihapus.")
        elif choice == "3":
            print("Program selesai.")
            break
        else:
            print("Pilihan tidak valid. Silakan coba lagi.")
        
        display_stack(stack)

if __name__ == "__main__":
    main()
