package com.bsuir.web7lab.model;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import lombok.ToString;

import java.io.Serializable;

@Data
@ToString
@AllArgsConstructor
@NoArgsConstructor
public class User implements Serializable{
    private int id;
    private String login;
    private byte[] passw;

    public User(String login, byte[] passw) {
        this.login = login;
        this.passw = passw;
    }


}