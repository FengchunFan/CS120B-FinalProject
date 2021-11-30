#define ROW4 4
#define COL1 3
#define COL2 2
#define COL3 1
#define COL4 0

////////////////////////////////////////////////////////////////////////////////
//Functionality - Gets input from a keypad via time-multiplexing
//Parameter: None
//Returns: A keypad button press else '\0'
unsigned char GetKeypadKey() {

        // Check keys in col 1
        KEYPADPORT = SetBit(0xFF,COL1,0); // Set Px4 to 0; others 1
        asm("nop"); // add a delay to allow PORTx to stabilize before checking
        if ( GetBit(~KEYPADPIN,ROW1) ) { return '1'; }
        if ( GetBit(~KEYPADPIN,ROW2) ) { return '4'; }
        if ( GetBit(~KEYPADPIN,ROW3) ) { return '7'; }
        if ( GetBit(~KEYPADPIN,ROW4) ) { return '*'; }

        // Check keys in col 2
        KEYPADPORT = SetBit(0xFF,COL2,0); // Set Px5 to 0; others 1
        asm("nop"); // add a delay to allow PORTx to stabilize before checking
        if ( GetBit(~KEYPADPIN,ROW1) ) { return '2'; }
        if ( GetBit(~KEYPADPIN,ROW2) ) { return '5'; }
        if ( GetBit(~KEYPADPIN,ROW3) ) { return '8'; }
        if ( GetBit(~KEYPADPIN,ROW4) ) { return '0'; }

        // Check keys in col 3
        KEYPADPORT = SetBit(0xFF,COL3,0); // Set Px6 to 0; others 1
        asm("nop"); // add a delay to allow PORTx to stabilize before checking
        if ( GetBit(~KEYPADPIN,ROW1) ) { return '3'; }
        if ( GetBit(~KEYPADPIN,ROW2) ) { return '6'; }
        if ( GetBit(~KEYPADPIN,ROW3) ) { return '9'; }
        if ( GetBit(~KEYPADPIN,ROW4) ) { return '#'; }

        // Check keys in col 4
        KEYPADPORT = SetBit(0xFF,COL4,0); // Set Px7 to 0; others 1
        asm("nop"); // add a delay to allow PORTx to stabilize before checking
        if (GetBit(~KEYPADPIN,ROW1) ) { return 'A'; }
        if (GetBit(~KEYPADPIN,ROW2) ) { return 'B'; }
        if (GetBit(~KEYPADPIN,ROW3) ) { return 'C'; }
        if (GetBit(~KEYPADPIN,ROW4) ) { return 'D'; }

        return '\0';
}

#endif //KEYPAD_H