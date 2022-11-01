//
// Created by Daniel Ferguson on 1/11/2022.
//

template<typename T>
Queue<T>::Queue() {length = 0;} //constructor

template<typename T>
Queue<T>::~Queue() {} //destructor

template<typename T>//add a node to the end of the queue
void Queue<T>::enqueue(const T& d) {
    if(length == maxLength()) {
        throw std::out_of_range("Queue is full");
    }
    int i;

    if(isEmpty()){
        LQ[length++] = d;
        }
    else{
        // start from the right end of the queue
        for(i = length - 1; i >= 0; i-- ){
            // if data is larger, shift existing item to right end
            if(d > LQ[i]){
                LQ[i+1] = LQ[i];
            }else{
                break;
            }
        }
        // insert the data
        LQ[i+1] = d;
        length++;
    }
}

template<typename T>//removes the last node in the queue
T Queue<T>::dequeue() {
    if(isEmpty()) {throw std::out_of_range("Queue is empty");}
    T temp = LQ[0];
    for(int i = 0; i < length; i++){
        LQ[i] = LQ[i+1];
    }
    length--;
    return temp;
}

template<typename T>
T& Queue<T>::front(){ //returns the head of the list
    if(isEmpty()) {throw std::out_of_range("Queue is empty");}
    LQ->move_to_tail();
    return LQ->get_current();
}

template<typename T>
bool Queue<T>::isEmpty() const{ //checks if the LQ is empty
    if(size()==0) {return true;}
    else {return false;}
}

template<typename T>
int Queue<T>::size() const {return length;} //returns the size of the queue

template<typename T>
int Queue<T>::maxLength() const {return sizeof LQ/sizeof LQ[0];} //returns the size of the queue


template<typename T>
int Queue<T>::queueDataReturn(std::ostream &out) {
    for(int i=0;i<length;i++){
        out << LQ[i] << " ";
    }
    std::cout<<std::endl;
    return 0;

}

//template<typename T>
//std::ostream& operator << (std::ostream& out, Queue<T>& LQin) { //prints all the nodes in the queue
//    for (int i = 0; i < LQin.size(); i++) { //loops for the length of the queue
//        T temp = LQin.dequeue(); //passes the head of the queue into temp
//        out << temp << " "; //passes temp into the output stream
//        LQin.enqueue(temp); //adds temp into the end of the queue
//    }
//    //The above function completely removes the queue and then adds it back in, so the queue is in the same order as it was before the function was called
//    return out; //returns the output stream

//}

template<typename T>
std::ostream& operator << (std::ostream& out, Queue<T>& LQin) {
    LQin.queueDataReturn(out);
    return out;
}