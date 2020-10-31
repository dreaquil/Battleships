CREATE TABLE ships
(
    id            INTEGER PRIMARY KEY,
    playerId      INTEGER,
    name          TEXT,
    symbol        TEXT,
    coordinates   TEXT
);

INSERT INTO ships VALUES (1,  1, "Aircraft Carrier", "A", "A1,A2,A3,A4,A5");
INSERT INTO ships VALUES (2,  2, "Aircraft Carrier", "A", "A1,A2,A3,A4,A5");
INSERT INTO ships VALUES (3,  1, "Battleship", "B", "B1,B2,B3,B4");
INSERT INTO ships VALUES (4,  2, "Battleship", "B", "B1,B2,B3,B4");
INSERT INTO ships VALUES (5,  1, "Cruiser", "C", "C1,C2,C3");
INSERT INTO ships VALUES (6,  2, "Cruiser", "C", "C1,C2,C3");
INSERT INTO ships VALUES (7,  1, "Submarine", "S", "D3,D4,D5");
INSERT INTO ships VALUES (8,  2, "Submarine", "S", "D3,D4,D5");
INSERT INTO ships VALUES (9,  1, "Destroyer", "D", "D1,D2");
INSERT INTO ships VALUES (10, 2, "Destroyer", "D", "D1,D2");

--SELECT * FROM ships;



CREATE TABLE games (
    id          INTEGER PRIMARY KEY,
    status      VARCHAR
);

INSERT INTO games
(status) VALUES ('WAITING_FOR_PLAYER_ONE');

CREATE TABLE AppUser (
    id          INTEGER PRIMARY KEY,
    username    VARCHAR UNIQUE,
    email       VARCHAR UNIQUE,
    password    VARCHAR,
    role        VARCHAR
);

INSERT INTO AppUser
(username, email, password, role) VALUES ('admin', 'admin@domain.com', 'admin', 'ROLE_ADMIN');

