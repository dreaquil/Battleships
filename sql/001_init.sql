CREATE TABLE ships (
    id                           INTEGER PRIMARY KEY,
    game_id                      VARCHAR,
    player_id                    VARCHAR,
    typw                         VARCHAR,
    top_left_row                 VARCHAR,
    top_left_column              VARCHAR,
    bottom_left_row              VARCHAR,
    bottom_right_column          VARCHAR
);

CREATE TABLE games (
    id          INTEGER PRIMARY KEY,
    status      VARCHAR
);

INSERT INTO games (status) VALUES ('WAITING_FOR_PLAYER_ONE');


CREATE TABLE players (
    id       INTEGER PRIMARY KEY,
    name     VARCHAR UNIQUE
);

CREATE TABLE pegs
(
    id               INTEGER PRIMARY KEY,
    game_id          VARCHAR,
    player_id        VARCHAR,
    row              VARCHAR,
    column           VARCHAR,
    colour           VARCHAR
);










CREATE TABLE AppUser (
    id          INTEGER PRIMARY KEY,
    username    VARCHAR UNIQUE,
    email       VARCHAR UNIQUE,
    password    VARCHAR,
    role        VARCHAR
);

INSERT INTO AppUser
(username, email, password, role) VALUES ('admin', 'admin@domain.com', 'admin', 'ROLE_ADMIN');


--SELECT * FROM ships;