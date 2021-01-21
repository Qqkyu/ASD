class Link {
    constructor(value) {
        this.value = value;
        this.next = null;
        this.prev = null;
        this.prevMin = null;
    }
}

class LinkedList {
    constructor() {
        this.first = null;
        this.last = null;
        this.min = null;
    }

    push(v) {
        let link = new Link(v);
        if(this.first === null) {
            this.first = this.last = this.min = link;
        }
        else {
            this.first.prev = link;
            link.next = this.first;
            this.first = link;

            if(v <= this.min.value) {
                link.prevMin = this.min;
                this.min = link;
            }
        }
    }

    pop() {
        if(this.first !== null) {
            let result = this.first;
            if(this.last === this.first) {
                this.first = this.last = this.min = null;
            }
            else {
                this.firt = result.next;
                this.first.prev = null;

                if(result === this.min) {
                    this.min = result.prevMin;
                }
            }
            return result.value;
        }
        return null;
    }

    upToMin() {
        if(this.min !== null) {
            this.first = this.min.next;
            this.min = this.min.prevMin;
            if(this.last === null) {
                this.first = null;
            }
            else {
                this.last.next = null;
            }
        }
    }

    print() {
        let l = this.first;
        let values = [];
        while(l !== null) {
            values.push(l.value);
            l = l.next;
        }
        console.log(`List: ${values.join(" ")}, min: ${list.min ? list.min.value : Number.NaN}`)
    }
}

let list = new LinkedList();

list.push(2);
list.push(3);
list.push(4);
list.push(5);
list.push(1);
list.push(6);
list.push(7);
list.push(8);
list.push(9);
list.push(10);

list.print();

list.upToMin();
list.print();
list.upToMin();
list.print();
