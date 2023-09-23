//
// Created by mi on 23.09.2023.
//

#ifndef COLB_SOLVER_GAME_H
#define COLB_SOLVER_GAME_H

#include "Colb.h"
#include <vector>
#include <stack>
#include <algorithm>

class Game {
    std::vector<Colb> m_colbs;
    struct Move{
        std::size_t from, to;
        Move(std::size_t from, std::size_t to){
            this->from = from;
            this->to = to;
        }
    };

    void move_color(Colb &from, Colb &to){
        while(true){
            if(from.colors.empty())
                break;

            if(to.colors.empty() || Colb::is_same_color(from.colors.back(), to.colors.back())){
                to.colors.emplace_back(from.colors.back());
                from.colors.pop_back();
            }
            else{
                break;
            }
        }

        bool from_solved = is_solved(from);
        bool to_solved = is_solved(to);

        if(from_solved)
            from.solved = true;

        if(to_solved)
            to.solved = true;
    }

    bool is_solved(const Colb &c){
        if(c.colors.size() != 4){
            return false;
        }

        int same_amount = 1;
        auto& colors = c.colors;
        auto colb_sz = colors.size();
        for(int i = 1; i < colb_sz; i++){
            if(Colb::is_same_color(colors[0], colors[i])){
                same_amount++;
            }
            else{
                break;
            }
        }
        if(same_amount == 4){
            return true;
        }
        return false;
    }

    bool can_move_color(Colb &from, Colb &to){
        bool moved = false;


        if(from.colors.empty())
            return moved;

        if(to.colors.size() == 4)
            return moved;

        if(from.solved || to.solved)
            return moved;

        auto& top_from = from.colors.back();


        if(!to.colors.empty()){
            if(!Colb::is_same_color(top_from, to.colors.back())){
                return moved;
            }

            int am_from = 1, am_to = to.colors.size();

            auto top = top_from;
            auto size = from.colors.size();
            int pos = size - 2;
            while(true){
                bool exists = (pos < size) && pos > -1;
                if(!exists)
                    break;

                if(Colb::is_same_color(top, from.colors[pos])){
                    pos--;
                    am_from++;
                }
                else{
                    break;
                }
            }

            if((am_from + am_to) > 4){
                return false;
            }

        }
        else{
                int diff_amount = 0;
                auto& colors = from.colors;
                auto colb_sz = colors.size();
                for(int i = 1; i < colb_sz; i++){
                    if(!Colb::is_same_color(colors[0], colors[i])){
                        diff_amount++;
                        break;
                    }
                }
                if(diff_amount == 0){
                    return false;
                }



        }


        moved = true;
        return moved;
    }


    std::string move_to_string(const Move &move){
        return "colb " + std::to_string(move.from + 1) + " to colb " + std::to_string(move.to + 1) + '\n';
    }

    bool all_colbs_solved(const std::vector<Colb> &colbs){
        for(auto& c : colbs){

            if(c.colors.empty()){
                continue;
            }

            if(!c.solved)
                return false;
        }
        return true;
    }

    std::vector<Move> get_possible_moves(std::vector<Colb>& state){

        auto size = state.size();

        std::vector<Move> possible_moves;

        for(int i = 0; i < size; i++){
            auto& from = state[i];

            for(int j = i+1; j < size; j++){
                auto& to = state[j];

                bool moved = can_move_color(from, to);

                if(moved){
                    possible_moves.emplace_back(i,j);
                }

            }
        }

        for(int i = size-1; i > -1; i--){
            auto& from = state[i];

            for(int j = 0; j < i; j++){
                auto& to = state[j];

                bool moved = can_move_color(from, to);

                if(moved){
                    possible_moves.emplace_back(i,j);
                }

            }
        }

        return possible_moves;
    }
public:

    Game(std::vector<Colb> &colbs) {
        m_colbs = colbs;
    }

    /*std::vector<std::string> solve() {
        std::vector<std::string> moves_str;
        dfs(m_colbs, moves_str);
        return moves_str;
    }*/
    /*std::cout << "stack sz: " << stack.size() << '\n';
    if(stack.size() > 16){
        while(moves_str.empty()){
            std::cout << "pop\n";
            stack.pop();
            moves_str = stack.top().second;
        }
        std::cout << moves_str.back();
        return moves_str;
    }*/

    std::vector<std::string> solve() {
        std::vector<std::string> moves_str;

        std::vector<std::vector<std::string>> avail;
        struct Data{
            std::vector<Colb> m_state;
            std::vector<std::string> m_moves;
            Data(std::vector<Colb> &state, std::vector<std::string> &moves){
                m_state = std::move(state);
                m_moves = std::move(moves);
            }
        };

        std::stack<Data> stack;
        auto colbs = m_colbs;
        stack.emplace(colbs, moves_str);
        int aboba = 0;
        while (!stack.empty()) {
            // Pop the top state from the stack
            auto[curr_state_colbs, moves_string] = stack.top();
            stack.pop();

//            std::cout << "stack_sz: " << stack.size() << '\n';

            if (all_colbs_solved(curr_state_colbs)) {
                moves_str = moves_string;
                break;
            }

            auto possible_moves = get_possible_moves(curr_state_colbs);
            for (const auto& move : possible_moves) {

                std::vector<Colb> saved_state = curr_state_colbs;
                auto str = moves_string;
                move_color(saved_state[move.from], saved_state[move.to]);
                str.emplace_back(move_to_string(move));

//                std::cout << "\n";
//                for(auto& s :  str)
//                    std::cout << s;
//                std::cout << "\n";

                stack.emplace(saved_state, str);
            }
            aboba++;
        }

        // If we get here, there is no solution
        std::cout << "iterations: " << aboba << '\n';
        std::cout << "the solution takes " << moves_str.size() << " moves" << '\n';

        return moves_str;
 /*       int less = INT32_MAX;
        int index = 0;
        for(int i = 0; i < avail.size(); i++){
            auto& sol = avail[i];
            int size = sol.size();

            if(size < less){
                index = i;
                less = size;
            }
        }
        std::cout << "the fastest solution takes " << avail[index].size() << " moves" << '\n';
        return avail[index];*/
    }

//        while (!colb_states_stack.empty()) {
//            auto[curr_state_colbs, str] = colb_states_stack.top();
//            colb_states_stack.pop();
//
//            //std::cout << "stack_sz: " << colb_states_stack.size() << '\n';
//
//            if (all_colbs_solved(curr_state_colbs)) {
//
//                return {"aboba"};
//            }
//
//            auto possible_moves = get_possible_moves(curr_state_colbs);
//
//            for (const auto& move : possible_moves) {
//                std::vector<Colb> saved_state = curr_state_colbs;
//                move_color(saved_state[move.from], saved_state[move.to]);
//
//
//
//                colb_states_stack.emplace(saved_state);
//            }
//        }
//
//        // If we get here, there is no solution
//        return {};
//    }



};

#endif //COLB_SOLVER_GAME_H
