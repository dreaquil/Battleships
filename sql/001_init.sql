CREATE TABLE games (
    id          INTEGER PRIMARY KEY,
    status      VARCHAR
);

INSERT INTO games (status) VALUES ('WAITING_FOR_PLAYER_ONE');


CREATE TABLE players (
    id       INTEGER PRIMARY KEY,
    name     VARCHAR UNIQUE
);

CREATE TABLE ships (
    id            INTEGER PRIMARY KEY,
    game_id       VARCHAR,
    player_id     VARCHAR,
    ship_id       VARCHAR,
    coordinates   VARCHAR
);

CREATE TABLE ship_classes
(
    id            INTEGER PRIMARY KEY,
    name          VARCHAR,
    symbol        VARCHAR,
    length        VARCHAR
);

INSERT INTO ship_classes (name, symbol, length) VALUES ("Aircraft Carrier", "A", 5);
INSERT INTO ship_classes (name, symbol, length) VALUES ("Battleship", "B", 4);
INSERT INTO ship_classes (name, symbol, length) VALUES ("Cruiser", "C", 3);
INSERT INTO ship_classes (name, symbol, length) VALUES ("Submarine", "S", 3);
INSERT INTO ship_classes (name, symbol, length) VALUES ("Destroyer", "D", 2);


CREATE TABLE pegs
(
    id            INTEGER PRIMARY KEY,
    game_id       VARCHAR,
    player_id     VARCHAR,
    coordinate    VARCHAR,
    colour        VARCHAR
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

CREATE TABLE ships
(
    id            INTEGER PRIMARY KEY,
    game_id       INTEGER,
    player_id     INTEGER,
    name          VARCHAR,
    symbol        VARCHAR,
    coordinates   VARCHAR
);


--SELECT * FROM ships;