

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
